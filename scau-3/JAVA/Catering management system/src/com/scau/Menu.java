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

public class Menu implements MenuList{

    /* 内部类：Dish */
    public class Dish implements Comparable<Dish> {
        String number;
        String name;
        String sort;
        double price;

        Dish(String name) {
            this(null, name, null, 0);
        }

        Dish(String name, String sort) {
            this(name, sort, 0.0);
        }

        Dish(String name, String sort, double price) {
            this.number = this.createNumber();
            this.name = name;
            this.sort = sort;
            this.price = price;
//            this(, name, sort, price);
        }

        Dish(String number, String name, String sort, double price) {
            this.number = number;
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
            return Objects.equals(name, dish.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name);
        }

        @Override
        public String toString() {
            return this.number + "\t" + this.name + "\t" + "\t" + this.price;
        }

        String createNumber() {
            while (true) {
                int number = (int) (Math.random() * 9000) + 1000;
                String num = Integer.toString(number);
                if (!searchByNameOrNumber(num)) {
                    return num;
                }
            }
        }

    }

    private TreeMap<String, TreeSet<Dish>> menu;
    private HashMap<String, String> numberToName;

    public Menu() {
        menu = new TreeMap<>();
        numberToName = new HashMap<>();
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
        Dish dish = new Dish(name, sort, price);
        menu.get(sort).add(dish);
        numberToName.put(dish.number, dish.name);
    }

    private void addDish(String number, String name, String sort, double price) {
        if (!menu.containsKey(sort)) {
            menu.put(sort, new TreeSet<>());
        }
        menu.get(sort).add(new Dish(number, name, sort, price));
        numberToName.put(number, name);
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

    private void removeDish(String nameOrNumber) {
        // 用dish比较就行了
        String name = getNameByNameOrNumber(nameOrNumber);
        String sort = searchByNameReturnSort(name);
        if (sort == null) {
            return;
        }
        Dish dish = new Dish(name);
        numberToName.remove(dish.number);
        menu.get(sort).remove(dish);
    }

    private String getNameByNameOrNumber(String nameOrNumber) {
        if (isNumber(nameOrNumber)) {
            return numberToName.get(nameOrNumber);
        }
        return nameOrNumber;
    }

    private void removeDishFromMenu() {
        String nameOrNumber = getNameOrNumber();
//        System.out.print("请输入菜的种类:");
//        String sort = input.next();
        removeDish(nameOrNumber);
    }

    private String getNameOrNumber() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名或编号:");
        return input.next();
    }

    private void change() {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入菜名或编号:");
        String nameOrNumber = input.next();
        System.out.print("请输入新菜名:");
        String newName = input.next();
        System.out.print("请输入新菜的种类:");
        String newSort = input.next();
        System.out.print("请输入新菜的价格:");
        double newPrice = inputDouble();
        addDish(newName, newSort, newPrice);
        removeDish(nameOrNumber);
    }

    public boolean search() {
        String nameOrNumber = getNameOrNumber();
        return searchByNameOrNumber(nameOrNumber);
    }

    private boolean searchByNameOrNumber(String nameOrNumber) {
        String name = getNameByNameOrNumber(nameOrNumber);
        return searchByNameReturnSort(name) != null;
    }

    private String searchByNameReturnSort(String name) {
        if (name == null) {
            return null;
        }
        Collection<TreeSet<Dish>> dishes = menu.values();
        for (TreeSet<Dish> aDishes :
                dishes) {
            Dish dish = new Dish(name);
            if (aDishes.contains(dish)) {
                return aDishes.first().sort;
            }
        }
        return null;
    }

    @Override
    public void traverse() {
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
            row.createCell(0).setCellValue("编号");
            row.createCell(1).setCellValue("菜名");
            row.createCell(2).setCellValue("价格");
            for (Dish aDish :
                    aMap.getValue()) {
                row = sheet.createRow(rowNum);
                row.createCell(0).setCellValue(aDish.number);
                row.createCell(1).setCellValue(aDish.name);
                row.createCell(2).setCellValue(aDish.price);
                rowNum++;
            }
        }

        // 写入磁盘
        FileOutputStream outputStream = new FileOutputStream("/home/yinglongyhy/Templates/test.xls");
        wb.write(outputStream);
        outputStream.close();
    }

    @Override
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
                String number = null;
                String name = null;
                double price = 0;
                HSSFCell cell = row.getCell(0);
                if (cell.getCellTypeEnum() == CellType.STRING) {
                    number = cell.getStringCellValue();
                }
                cell = row.getCell(1);
                if (cell.getCellTypeEnum() == CellType.STRING) {
                    name = cell.getStringCellValue();
                }
                cell = row.getCell(2);
                if (cell.getCellTypeEnum() == CellType.NUMERIC) {
                    price = cell.getNumericCellValue();
                }
                this.addDish(number, name, hssfSheet.getSheetName(), price);

            }
            fileInputStream.close();
        }

    }

    @Override
    public void menuConsole() throws IOException {
        int choice;
        while (true) {
            showChoice();

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
                case 8:
                    System.out.println(getNameByNameOrNumber("5153"));
                    break;
            }

        }
    }

    private void showChoice() {
        System.out.println("--------------" + "请选择" + "--------------");
        System.out.println("1、增加菜式");
        System.out.println("2、删除菜式");
        System.out.println("3、修改菜式");
        System.out.println("4、查找菜式");
        System.out.println("5、遍历菜式");
        System.out.println("6、保存菜式");
        System.out.println("7、退出菜单控制台");
    }

    @Override
    public Dish getDish(String nameOrNumber) {
        String sort = searchByNameReturnSort(nameOrNumber);
        if (sort != null) {
            Set<Dish> dishes = menu.get(sort);
            for (Dish aDish :
                    dishes) {
                if (aDish.number.equals(nameOrNumber) || aDish.name.equals(nameOrNumber)) {
                    return aDish;
                }
            }
        }
        return null;
    }

    private boolean isNumber(String nameOrNumber) {
        String regex = "^[1-9]\\d{3}";
        return nameOrNumber.matches(regex);
    }

}
