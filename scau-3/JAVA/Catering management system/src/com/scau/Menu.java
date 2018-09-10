package com.scau;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.CellType;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.Collator;
import java.util.*;

/*
    目标：添加种类
    修改：内部类，addDish(), addDishToMenu(), removeDish(), removeDishFromMenu(), change(), search(), traverse(), writeToXls(), readFromXls()
 */

public class Menu {

    /* 内部类：Dish */
    public class Dish implements Comparable<Dish> {
        String name;
        String sort;
        double price;

        Dish(String name, String sort) {
            this(name, sort, 0.0);
        }

        Dish(String name, String sort, double price) {
            this.name = name;
            this.sort = sort;
            this.price = price;
        }

        @Override
        public int compareTo(Dish Dish) {
            Comparator cmp = Collator.getInstance(java.util.Locale.CHINA);
            return ((Collator) cmp).compare(this.name, Dish.name);
//            return this.name.compareTo(Dish.name);
//            return Double.compare(this.price, Dish.price);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Dish dish = (Dish) o;
            return Objects.equals(name, dish.name) &&
                    Objects.equals(sort, dish.sort);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, sort);
        }

        @Override
        public String toString() {
            return this.name + "\t" + this.price;
        }
    }

    private TreeMap<String, TreeSet<Dish>> menu;

    public Menu() {
        menu = new TreeMap<>();
    }

    private double inputDouble() {
        Scanner input;
        double price;

        while (true) {
            try {
                input = new Scanner(System.in);
                price = input.nextDouble();
            } catch (InputMismatchException e) {
                System.out.println("请输入浮点型");
                continue;
            }
            break;
        }
        return price;
    }

    private int inputInt() {
        Scanner input;
        int number;

        while (true) {
            try {
                input = new Scanner(System.in);
                number = input.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("请输入整型型");
                continue;
            }
            break;
        }
        return number;
    }

    private void addDish(String name, String sort, double price) {
        if (!menu.containsKey(sort)) {
            menu.put(sort, new TreeSet<>());
        }
        menu.get(sort).add(new Dish(name, sort, price));
    }

    private void addDishToMenu() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        String name = input.next();
        System.out.print("请输入菜的种类:");
        String sort = input.next();
        System.out.print("请输入菜的价格:");
        double price = this.inputDouble();
        addDish(name, sort, price);
    }

    private void removeDish(String name, String sort) {
        Dish dish = new Dish(name, sort);
        if (menu.containsKey(sort)) {
            menu.get(sort).remove(dish);
        }
    }

    private void removeDishFromMenu() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        String name = input.next();
        System.out.print("请输入菜的种类:");
        String sort = input.next();
        removeDish(name, sort);
    }

    private void change() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        String name = input.next();
        System.out.print("请输入菜的种类:");
        String sort = input.next();
        if (!menu.containsKey(sort)) {
            return;
        }
        if (!menu.get(sort).contains(new Dish(name, sort))) {
            return;
        }
        System.out.print("请输入新菜名:");
        String newName = input.next();
        System.out.print("请输入新菜的种类:");
        String newSort = input.next();
        System.out.print("请输入新菜的价格:");
        double newPrice = inputDouble();
        addDish(newName, newSort, newPrice);
        removeDish(name, sort);
    }

    private boolean search() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名:");
        String name = input.next();
        System.out.print("请输入菜的种类:");
        String sort = input.next();
        if (!menu.containsKey(sort)) {
            return false;
        }
        return menu.get(sort).contains(new Dish(name, sort));
    }

    private void traverse() {
        for (Map.Entry<String, TreeSet<Dish>> aMap :
                menu.entrySet()) {
            System.out.println("-----------------------------" + aMap.getKey() + "-----------------------------");
            for (Dish aSet :
                    aMap.getValue()) {
               System.out.println(aSet);
            }
        }
    }

    private void writeToXls() throws IOException {

        HSSFWorkbook wb = new HSSFWorkbook();

        for (Map.Entry<String, TreeSet<Dish>> aMap :
                menu.entrySet()) {
            HSSFSheet sheet = wb.createSheet(aMap.getKey());
            HSSFRow row;
            int rowNum = 1;
            row = sheet.createRow(0);
            row.createCell(0).setCellValue("菜名");
            row.createCell(1).setCellValue("价格");
            for (Dish aDish :
                    aMap.getValue()) {
                row = sheet.createRow(rowNum);
                row.createCell(0).setCellValue(aDish.name);
                row.createCell(1).setCellValue(aDish.price);
                rowNum++;
            }
        }

        // 写入磁盘
        FileOutputStream outputStream = new FileOutputStream("/home/yinglongyhy/Templates/test.xls");
        wb.write(outputStream);
        outputStream.close();
    }

    public void readFromXls() throws IOException {
        FileInputStream fileInputStream;
        try {
            fileInputStream = new FileInputStream("/home/yinglongyhy/Templates/test.xls");
        } catch (FileNotFoundException e) {
            System.out.println("后台暂无数据");
            return;
        }
        HSSFWorkbook workbook = new HSSFWorkbook(fileInputStream);

        for (int sheetNum = 0; sheetNum < workbook.getNumberOfSheets(); sheetNum++) {
            HSSFSheet hssfSheet = workbook.getSheetAt(sheetNum);

            for (int rowNum = 1; rowNum <= hssfSheet.getLastRowNum(); rowNum++) {
                HSSFRow row = hssfSheet.getRow(rowNum);
                String name = null;
                double price = 0;
                HSSFCell cell = row.getCell(0);
                if (cell.getCellTypeEnum() == CellType.STRING) {
                    name = cell.getStringCellValue();
                }
                // 下面if出问题
                cell = row.getCell(1);
                if (cell.getCellTypeEnum() == CellType.NUMERIC) {
                    price = cell.getNumericCellValue();
                }
                this.addDish(name, hssfSheet.getSheetName(), price);

            }
            fileInputStream.close();
        }

    }

    public void menuConsole() throws IOException {
        int choice;
        while (true) {
            System.out.println("--------------" + "请选择" + "--------------");
            System.out.println("1、增加菜式");
            System.out.println("2、删除菜式");
            System.out.println("3、修改菜式");
            System.out.println("4、查找菜式");
            System.out.println("5、遍历菜式");
            System.out.println("6、保存菜式");
            System.out.println("7、退出菜单控制台");

            choice = inputInt();

            switch (choice) {
                case 1:
                    addDishToMenu();
                    break;

                case 2:
                    removeDishFromMenu();
                    break;

                case 3:
                    change();
                    break;

                case 4:
                    if (search()) {
                        System.out.println("找到了");
                    } else {
                        System.out.println("未找到");
                    }
                    break;

                case 5:
                    traverse();
                    break;

                case 6:
                    writeToXls();
                    break;

                case 7:
                    return;
            }

        }
    }

}
