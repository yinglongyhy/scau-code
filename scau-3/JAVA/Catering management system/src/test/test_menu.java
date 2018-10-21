package test;


import com.scau.Menu;

import java.io.IOException;

public class test_menu {


    public static void main(String[] args) throws IOException {
        Menu newMenu = new Menu();

        newMenu.readFromXls();

        newMenu.menuConsole();
    }

}


