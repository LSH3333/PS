if(dir == 0) { // 우상 
        let t = Math.min(W - x, H - y)         
        if(T - t < 0)  {
            x = x + dx[0] * T 
            y = y + dy[0] * T
            break
        }
        T -= t         
        x = x + dx[0] * t
        y = y + dy[0] * t
        if(x == W && y == H) dir = 2
        else if(x == W) dir = 1 
        else if(y == H) dir = 3
    }
    else if(dir == 1) { // 좌상 
        let t = Math.min(x, H - y)
        if(T - t < 0)  {
            x = x + dx[1] * T 
            y = y + dy[1] * T 
            break 
        }
        T -= t 
        x = x + dx[1] * t 
        y = y + dy[1] * t 
        if(x == 0 && y == H) dir = 3
        else if(x == 0) dir = 0 
        else if(y == H) dir = 2 
    }
    else if(dir == 2) { // 좌하 
        let t = Math.min(x, y) 
        if(T - t < 0) {
            x = x + dx[2] * T 
            y = y + dy[2] * T 
            break 
        }
        T -= t 
        x = x + dx[2] * t 
        y = y + dy[2] * t 
        if(x == 0 && y == 0) dir = 0 
        else if(x == 0) dir = 3
        else if(y == 0) dir = 1
    }
    else { // dir == 3 우하 
        let t = Math.min(W - x, y) 
        if(T - t < 0) {
            x = x + dx[3] * T 
            y = y + dy[3] * T 
            break 
        }
        T -= t 
        x = x + dx[3] * t 
        y = y + dy[3] * t 
        if(x == W && y == 0) dir = 1
        else if(x == W) dir = 2
        else if(y == 0) dir = 0
    }