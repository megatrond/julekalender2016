import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.image.Raster;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Luke13 {
	public static void main(String[] args) throws IOException {
		int size = 10_000;

		BufferedImage bi = new BufferedImage(size, size, BufferedImage.TYPE_BYTE_BINARY);
		Graphics2D g = bi.createGraphics();

		g.setColor(Color.BLACK);
		g.fillRect(0, 0, size, size);

		BufferedReader br = new BufferedReader(new FileReader("../../problems/13.txt"));
		String line;
		while((line = br.readLine()) != null) {
			Pattern pattern = Pattern.compile("^(turn on)?(turn off)?(toggle)? (\\d+),(\\d+) through (\\d+),(\\d+)$");
			Matcher matcher = pattern.matcher(line);
			if(!matcher.matches()) throw new RuntimeException();
			int x0 = Integer.valueOf(matcher.group(4));
			int y0 = Integer.valueOf(matcher.group(5));
			int x1 = Integer.valueOf(matcher.group(6));
			int y1 = Integer.valueOf(matcher.group(7));
			if(matcher.group(1) != null) {
				g.setColor(Color.WHITE);
				g.setPaintMode();
			} else if(matcher.group(2) != null) {
				g.setColor(Color.BLACK);
				g.setPaintMode();
			} else if(matcher.group(3) != null) {
				g.setXORMode(new Color(0, 0, 0));
				g.fillRect(x0, y0, x1-x0+1, y1-y0+1);
				g.setXORMode(new Color(255, 255, 255));
			}
			g.fillRect(x0, y0, x1-x0+1, y1-y0+1);
		}

		Raster data = bi.getData();
		int[] pixelBuf = new int[1];
		int on = 0;
		for(int x = 0; x < size; x++) {
			for(int y = 0; y < size; y++) {
				int[] pixel = data.getPixel(x, y, pixelBuf);
				if(pixel[0] != 0) {
					on++;
				}
			}
		}
		System.out.println(on);
	}
}
