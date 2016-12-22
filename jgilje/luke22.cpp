#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#include <limits>

#include "include/json.hpp"

using json = nlohmann::json;

struct coord {
    int x = 0;
    int y = 0;

    bool operator==(const coord& other) {
        return x == other.x && y == other.y;
    }
};

struct rect {
    coord ll;
    coord lr;
    coord ul;
    coord ur;

    void extend(const rect& other) {
        ll.x = std::min(ll.x, other.ll.x);
        ll.y = std::min(ll.y, other.ll.y);

        lr.x = std::max(lr.x, other.lr.x);
        lr.y = std::min(lr.y, other.lr.y);

        ul.x = std::min(ul.x, other.ul.x);
        ul.y = std::max(ul.y, other.ul.y);

        ur.x = std::max(ur.x, other.ur.x);
        ur.y = std::max(ur.y, other.ur.y);
    }

    uint32_t width() {
        uint32_t l_width = static_cast<uint32_t>(lr.x - ll.x);
        uint32_t u_width = static_cast<uint32_t>(ur.x - ul.x);

        if (l_width != u_width) {
            std::cout << "fishy";
        }

        return l_width;
    }

    uint32_t height() {
        uint32_t l_height = static_cast<uint32_t>(ul.y - ll.y);
        uint32_t r_height = static_cast<uint32_t>(ur.y - lr.y);

        if (l_height != r_height) {
            std::cout << "fishy";
        }

        return l_height;
    }

    int x_offset() {
        return ll.x;
    }

    int y_offset() {
        return ll.y;
    }
};

static rect create_rect(coord ll, coord ur) {
    rect ret;

    ret.ll = ll;
    ret.lr = {ur.x, ll.y};
    ret.ul = {ll.x, ur.y};
    ret.ur = ur;

    return ret;
};

static std::vector<bool> read(std::string file) {
    std::ifstream f(file);
    json j;
    f >> j;

    std::vector<bool> results;

    auto create = [] (auto it) {
        return create_rect({(*it)[0], (*it)[1]}, {(*it)[2], (*it)[3]});
    };

    for (auto& i1 : j) {
        if (i1.empty()) {
            results.emplace_back(true);
            continue;
        }

        auto it = i1.begin();
        rect res = create(it);
        while (it != i1.end()) {
            rect next = create(it);
            res.extend(next);
            ++it;
        }

        int tx = res.x_offset();
        int ty = res.y_offset();
        uint32_t size = res.width() * res.height();
        std::unique_ptr<bool[]> arr(new bool[size]);
        memset(arr.get(), 0, sizeof(bool) * size);

        for (auto jt = i1.begin(); jt != i1.end(); ++jt) {
            int start_y = int((*jt)[1]);
            int end_y = int((*jt)[3]);

            int start_x = int((*jt)[0]);
            int end_x = int((*jt)[2]);

            for (int y = start_y; y < end_y; y++) {
                int dest_y = y - ty;

                for (int x = start_x; x < end_x; x++) {
                    int dest_x = x - tx;
                    uint32_t pos = static_cast<uint32_t>(dest_y) * res.width() + static_cast<uint32_t>(dest_x);
                    if (arr[pos]) {
                        arr[0] = false;
                        y = end_y;
                        jt = i1.end();
                        --jt;
                        break;
                    }
                    arr[pos] = true;
                }
            }

        }

        bool complete = true;
        for (uint32_t i = 0; i < size; i++) {
            complete &= arr[i];
        }
        results.emplace_back(complete);

    }

    return results;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }

    auto results = read(argv[1]);
    for (auto res : results) {
        std::cout << std::boolalpha << res << ", ";
    }
    std::cout << std::endl;
}
