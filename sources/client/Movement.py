def getMovements(target)
        movement = []
        if (target == 0):
            return (movement)
        y = 1
        x = 0
        res = 0
        while (res < target):
            res += y x 2
        if (res - y > case):
            res -= y x 2
            x = case - res
        else:
            x = case - res
        while (y > 0):
            movement.append('avance')
            y--
        if (x > 0):
            movement.append('droite')
            while (x > 0):
                movement.append('avance')
                x--
        elif (x < 0):
            movement.append('gauche')
            while (x > 0):
                movement.append('avance')
                x++
        return (movement)
