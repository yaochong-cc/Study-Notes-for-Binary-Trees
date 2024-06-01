package com.string;

import java.sql.SQLOutput;

public class StringExercise {
    public static void main(String[] args) {
        String s1="abc";
        String s2=new String("abc");
        System.out.println(s1.equals(s2));//T
        System.out.println(s1==s2);//F

        System.out.println(s1==s2.intern());//T
        System.out.println(s2==s2.intern());//F  //s2指向堆，s2.intern()指向常量池。
        //当调用intern方法时，如果池已经包含一个等于次String 对象的字符串（用equals(Object)方法确定），
        //则返回池中的字符串。否则，将次String对象添加到池中，并返回String对象的引用。
        //b.intern() 方法最终返回的是常量池的地址(对象）
        //
    }
}
