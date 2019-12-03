package core.java;

import java.io.File;

public class OS {
	
	public boolean my_mkdir(String path) {
		File file = null;
		try {
			file = new File(path);
			if (!file.exists()) {
				return file.mkdirs();
			}
			else {
				return false;
			}
		}
		catch (Exception e) {			
		}
		finally {
			file = null;
		}
		return false;
	}

	
}
