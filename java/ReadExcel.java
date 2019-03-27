import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReadExcel {

    public void readExcel() throws IOException {
        File file = new File("/Users/ma/Downloads/demo.xlsx");
        FileInputStream inputStream = new FileInputStream(file);
        Workbook wb = new XSSFWorkbook(inputStream);
        org.apache.poi.ss.usermodel.Sheet sheet = wb.getSheetAt(0);
        int firstRowNum = sheet.getFirstRowNum();
        int lastRowNum = sheet.getLastRowNum();
        Row row = sheet.getRow(firstRowNum);
        int firstCellNum = row.getFirstCellNum();
        int lastCellNum = row.getLastCellNum();

        int i = firstRowNum;
        for (; i < lastRowNum + 1; i++) {
            row = sheet.getRow(i);
            List<Object> colList = new ArrayList<Object>();
            if (row == null) {
                continue;
            }
            boolean allBlank = true;
            for (int j = firstCellNum; j < lastCellNum; j++) {
                Cell cell = row.getCell(j);
                Object value = "";
                if (cell == null) {
                    colList.add(value);
                    continue;
                }
                value = cell.toString();
                System.out.println(value);
            }
        }
        wb.close();
    }
}
