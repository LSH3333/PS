import java.io.BufferedReader
import java.io.InputStreamReader


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    var left_x1 = _s[0].toInt()
    var left_y1 = _s[1].toInt()
    var right_x1 = _s[2].toInt()
    var right_y1 = _s[3].toInt()
    _s = br.readLine().split(' ')
    var left_x2 = _s[0].toInt()
    var left_y2 = _s[1].toInt()
    var right_x2 = _s[2].toInt()
    var right_y2 = _s[3].toInt()

    if (left_x1 > left_x2) {
        val temp_left_x = left_x2
        val temp_left_y = left_y2
        val temp_right_x = right_x2
        val temp_right_y = right_y2
        left_x2 = left_x1
        left_y2 = left_y1
        right_x2 = right_x1
        right_y2 = right_y1
        left_x1 = temp_left_x
        left_y1 = temp_left_y
        right_x1 = temp_right_x
        right_y1 = temp_right_y
    }

    var answer = ""
    if(right_x1 == left_x2)
    {
        if(right_y1 == left_y2 || left_y1 == right_y2) answer = "POINT";
        else if(left_y2 > right_y1) answer = "NULL";
        else if(left_y1 > right_y2) answer = "NULL";
        else answer = "LINE";
    }
    else if(right_x1 > left_x2)
    {
        if(right_y1 == left_y2) answer = "LINE";
        else if(left_y1 == right_y2) answer = "LINE";
        else if(right_y1 < left_y2) answer = "NULL";
        else if(left_y1 > right_y2) answer = "NULL";
        else answer = "FACE";
    }
    else
        answer = "NULL"

    println(answer)

}