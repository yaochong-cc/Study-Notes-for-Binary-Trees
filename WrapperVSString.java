package com.wrapper;

public class WrapperVSString {
    public static void main(String[] args) {
        //包装类转String
        Integer i=100;
        //方式1
        String str1 =i+"";//i还是Integer
        //方式2
        String str2=i.toString();
        //方式类
        String str3=String.valueOf(i);

        //String 转包装类
        String str ="12345";
        Integer i2=Integer.parseInt(str);
        Integer i3=new Integer(str);//构造器
    }
}
