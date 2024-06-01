package com.wrapper;

public class Integer01 {
    public static void main(String[] args) {
        int n1=100;
        //手动装箱
        Integer integer=new Integer(n1);//没有问题只是不推荐手动装箱
        Integer integer1 =Integer.valueOf(n1);
        //手动拆箱：
        int i=integer.intValue();


        //jdk5以后，就可以自动装箱和自动拆箱。
        int n2=200;
        Integer integer2=n2;//自动装箱
        int n3 =integer2;//自动拆箱


    }
}
