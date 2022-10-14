import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var limit = arrayOf(0,0,0)
var bottle = arrayOf(0, 0, 0)
var mark = Array<Array<Array<Boolean>>> (210){Array<Array<Boolean>>(210) {Array<Boolean>(210){false} } }
var answer = ArrayList<Int>()

fun dfs()
{
    if(bottle[0] == 0) answer.add(bottle[2])

    for(i in 0 until 3)
    {
        if(bottle[i] == 0) continue;

        for(j in 0 until 3)
        {
            if(i == j) continue
            if(bottle[j] == limit[j]) continue
            var toPour = limit[j] - bottle[j]
            var i_before = bottle[i]
            var j_before = bottle[j]

            if(bottle[i] - toPour >= 0)
            {
                bottle[i] -= toPour
                bottle[j] += toPour
            }
            else
            {
                bottle[j] = bottle[i] + bottle[j]
                bottle[i] = 0
            }
            if(mark[bottle[0]][bottle[1]][bottle[2]])
            {
                bottle[i] = i_before
                bottle[j] = j_before
                continue
            }
            mark[bottle[0]][bottle[1]][bottle[2]] = true
            dfs()
            mark[bottle[0]][bottle[1]][bottle[2]] = false
            bottle[i] = i_before
            bottle[j] = j_before
        }
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    val A = Integer.parseInt(_s[0])
    val B = Integer.parseInt(_s[1])
    val C = Integer.parseInt(_s[2])
    limit[0] = A; limit[1] = B; limit[2] = C
    bottle[0] = 0; bottle[1] = 0; bottle[2] = C
    mark[0][0][C] = true

    dfs()

    answer.sort()
    var new_answer = ArrayList<Int>()
    for(x in answer)
    {
        if(!new_answer.contains(x)) new_answer.add(x)
    }
    for(x in new_answer) print("$x ")
}