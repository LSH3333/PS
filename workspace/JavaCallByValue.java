// https://tose33.tistory.com/937

import java.io.IOException;

class Type {
    public int num;
    public int getNum() {
        return num;
    }
    public void setNum(int _num) {
        num = _num;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Type a = new Type();
        a.setNum(1);
        foo(a);
        System.out.println(a.getNum()); // 1
    }

    static void foo(Type type) {
        type = new Type();
        type.setNum(2);
    }
}


//    static void foo(Type type) {
//        type.setNum(2);
//    }
