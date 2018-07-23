package com.scau;


import java.util.Objects;

public class test<T extends Comparable<T>> {
    public T data;

    public test(T data) {
        this.data = data;
    }

    public int ma(test<T> b) {
        return this.data.compareTo(b.data);
    }

    public static void main(String[] args) {
//        test<String> a = new test<>("aaa");
//        test<String> b = new test<>("aaa");
//        System.out.println(a.ma(b));
        test<String> t = new test<>("jjj");
        String ch = new String("bbb");
        System.out.println(ch);
        t.doit(ch);
        System.out.println(ch);
    }

    public void doit(String ch) {
        ch = "aaa";
    }

}
