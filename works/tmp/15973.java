import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        int left_x1 = Integer.parseInt(_s[0]);
        int left_y1 = Integer.parseInt(_s[1]);
        int right_x1 = Integer.parseInt(_s[2]);
        int right_y1 = Integer.parseInt(_s[3]);
        _s = br.readLine().split(" ");
        int left_x2 = Integer.parseInt(_s[0]);
        int left_y2 = Integer.parseInt(_s[1]);
        int right_x2 = Integer.parseInt(_s[2]);
        int right_y2 = Integer.parseInt(_s[3]);

        if(left_x1 > left_x2)
        {
            int temp_left_x = left_x2;
            int temp_left_y = left_y2;
            int temp_right_x = right_x2;
            int temp_right_y = right_y2;

            left_x2 = left_x1;
            left_y2 = left_y1;
            right_x2 = right_x1;
            right_y2 = right_y1;

            left_x1 = temp_left_x;
            left_y1 = temp_left_y;
            right_x1 = temp_right_x;
            right_y1 = temp_right_y;
        }

        String answer;
        if(right_x1 == left_x2)
        {
            // 왼쪽 사각형 우측상단 점과, 오른쪽 사각형 좌측하단 점이 같을때 or
            // 왼쪽 사각형 우측하단 점과, 오른짝 사각형 좌측상단 점이 같을때 POINT
            if(right_y1 == left_y2 || left_y1 == right_y2) answer = "POINT";
                // 왼쪽 사각형의 윗면이, 오른쪽 사각형의 아랫면보다 아래 있을때
            else if(left_y2 > right_y1) answer = "NULL";
                // 왼쪽 사각형의 아랫면이, 오른쪽 사각형의 윗면보다 위에 있을때
            else if(left_y1 > right_y2) answer = "NULL";
            else answer = "LINE";
        }
        // 오른쪽 사각형의 왼쪽면이, 왼쪽 사각형의 오른쪽 면보다 왼쪽에 있을 경우
        else if(right_x1 > left_x2)
        {
            // 왼쪽 사각형의 윗면과, 오른쪽 사각형의 아랫면이 같을떄
            if(right_y1 == left_y2) answer = "LINE";
                // 왼쪽 사각형의 아랫면과, 오른쪽 사각형의 윗면이 같을때
            else if(left_y1 == right_y2) answer = "LINE";
                // 왼쪽 사각형의 윗면이, 오른쪽 사각형의 아랫면보다 아래 있을때
            else if(right_y1 < left_y2) answer = "NULL";
                // 왼쪽 사각형의 아랫면이, 오른쪽 사각형의 윗면보다 위에 있을때
            else if(left_y1 > right_y2) answer = "NULL";
            else answer = "FACE";
        }
        // 왼쪽 사각형의 오른쪽면이, 오른쪽 사각형의 왼쪽면보다 왼쪽에 있을때
        else
            answer = "NULL";

        System.out.println(answer);
    }

}
