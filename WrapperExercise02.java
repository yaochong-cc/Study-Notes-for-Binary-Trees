package com.wrapper;

public class WrapperExercise02 {
    public static void main(String[] args) {
        Integer i=new Integer(1);
        Integer j=new Integer(1);
        System.out.println(i==j);

        Integer m=1;
        Integer n=1;
        System.out.println(m==n);

        Integer x=128;
        Integer y=128;
        System.out.println(x==y);
        System.out.println("-----------------");

        Integer i9=127;
        Integer i10=new Integer(127);
        System.out.println(i9==i10);//F

        Integer i11=127;
        int i12=127;
        System.out.println(i11==i12);//T//只要有基本数据类型，判断的就是值是否相等


        Integer i13 =128;
        int i14=128;
        System.out.println(i13==114);//F
    }
}
