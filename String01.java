package com.string;

public class String01 {
    public static void main(String[] args) {
        //字符串一个字符无论是汉字还是字母都占两个字节
        //String是final类，不能被其他类继承
        //String 类实现了接口Serializable[String可以串行化，可以在网络传输】
        //                 Comparable [String 对象可以比较大小]



        String name="jack";
        name ="tom";
        //Stirng 有属性 private final char value[]用于存放字符串内容。一定要注意value是final类型，不可修改地址。【即value不可指向新的地址，单个字符内容是可以变化的】
        final char[] value={'a','b','c'};
        char []v={'t','o','m'};
        value[0]='H';//改变单个字符的值，没有问题。
//        value=v;//出错
    }
}
