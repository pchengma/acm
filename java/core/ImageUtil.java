package core;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import javax.imageio.ImageIO;

public class ImageUtil {
	
	public static void main(String[] args) throws IOException {
		// Please remember manually add fig.jpg file to the current directory.
		File originalFile = new File("fig.jpg");
		BufferedImage image = ImageIO.read(originalFile);
		Graphics g = image.getGraphics();
        g.setColor(Color.RED);
        g.drawRect(100, 100, 100, 100);
        FileOutputStream out = new FileOutputStream("fig.jpg");
        ImageIO.write(image, "jpeg", out);
	}
	
}
