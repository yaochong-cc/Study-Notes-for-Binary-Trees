package com.string;

import java.sql.SQLOutput;

class Person{
    String name;
}
public class StringExercise02 {
    public static void main(String[] args) {
        Person p1=new Person();
        p1.name="chencheng";
        Person p2=new Person();
        p2.name="chencheng";

        System.out.println(p1.name.equals(p2.name));//T
        System.out.println(p1.name==p2.name);//T
        System.out.println(p1.name=="chencheng");//T

        String s1=new String("ABCD");
        String s2=new String("ABCD");
        System.out.println(s1==s2);//F
    }
}
