package com.scau;

import java.io.IOException;

/**
 * @author yinglongyhy
 */
public interface MenuList {
    void traverse();
    void readFromXls() throws IOException;
    void menuConsole() throws IOException;

    Menu.Dish getDish(String nameOrNumber);
}
