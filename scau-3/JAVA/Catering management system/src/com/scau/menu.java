package com.scau;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import java.io.*;
import java.text.Collator;
import java.util.*;

import static org.apache.poi.ss.usermodel.CellType.NUMERIC;
import static org.apache.poi.ss.usermodel.CellType.STRING;

public class menu {

    /* 内部类：dish */
    public class dish implements Comparable<dish> {
        public String name;
        public double price;

        @Override
        public int compareTo(dish dish) {
            Comparator cmp = Collator.getInstance(java.util.Locale.CHINA);
            return ((Collator) cmp).compare(this.name, dish.name);
//            return this.name.compareTo(dish.name);
//            return Double.compare(this.price, dish.price);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            dish dish = (dish) o;
            return Objects.equals(name, dish.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name);
        }

        @Override
        public String toString() {
            return this.name + "\t" + this.price;
        }
    }

    private Set<dish> menuSet;

    public menu() {
        menuSet = new TreeSet<>();
    }

    private boolean add(String name, double price) {
        dish newdish = new dish();
        newdish.name = name;
        newdish.price = price;

        return this.menuSet.add(newdish);
    }

    public boolean addToMenu() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        String name = input.next();
        System.out.print("请输入菜的价格:");
        double price = input.nextDouble();
        return add(name, price);
    }

    private boolean remove(String name) {
        dish rmdish = new dish();
        rmdish.name = name;
        return this.menuSet.remove(rmdish);
    }

    public boolean removeFromMenu() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        String name = input.next();
        return remove(name);
    }

    public boolean change() {
        if (!removeFromMenu()) {
            return false;
        }
        return addToMenu();
    }

    public boolean search() {
        dish searchdish = new dish();
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        searchdish.name = input.next();

        return this.menuSet.contains(searchdish);
    }

    public void traverse() {
        for (dish aMenuSet : this.menuSet) {
            System.out.println(aMenuSet);
        }
    }

    public void writeToXls() throws IOException {

        HSSFWorkbook wb = new HSSFWorkbook();
        HSSFSheet sheet = wb.createSheet();

        HSSFRow row = null;
        int rowNum = 1;
        row = sheet.createRow(0);
        row.createCell(0).setCellValue("菜名");
        row.createCell(1).setCellValue("价格");
        for (dish eachDish :
                this.menuSet) {
            row = sheet.createRow(rowNum);
            row.createCell(0).setCellValue(eachDish.name);
            row.createCell(1).setCellValue(eachDish.price);
            rowNum++;
        }

        // 写入磁盘
        FileOutputStream outputStream = new FileOutputStream("/home/yinglongyhy/Templates/test.xls");
        wb.write(outputStream);
        outputStream.close();

    }

    public void readFromXls() throws IOException {
        File file = new File("/home/yinglongyhy/Templates/test.xls");
        FileInputStream read_file = new FileInputStream(file);
        HSSFWorkbook workbook = new HSSFWorkbook(read_file);

        HSSFSheet sheet = workbook.getSheetAt(0);

        for (int rowNum = 1; rowNum <= sheet.getLastRowNum(); rowNum++) {
            HSSFRow row = sheet.getRow(rowNum);
            if (row == null) {
                continue;
            }
//            for (int cellNum = 0; cellNum <= row.getLastCellNum(); cellNum++) {
//                HSSFCell cell = row.getCell(cellNum);
//            }


            String name = null;
            double price = 0;

            HSSFCell cell = row.getCell(0);
            if (cell.getCellTypeEnum() == STRING) {
                name = cell.getStringCellValue();
            }
            cell = row.getCell(1);
            if (cell.getCellTypeEnum() == NUMERIC) {
                price = cell.getNumericCellValue();
            }

            add(name, price);
        }
        read_file.close();

    }

}
