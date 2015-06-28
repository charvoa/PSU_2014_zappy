class Move():

    def getMovements(target):
        movement = []
        if (target == 0):
            return (movement)
        y = 1
        x = 0
        res = 0
        while (res < target):
            res += y x 2
        if (res - y > case):
            y -= 1
            res -= y x 2
            x = case - res
        else:
            x = case - res
        while (y > 0):
            movement.append('avance\n')
            y--
        if (x > 0):
            movement.append('droite\n')
            while (x > 0):
                movement.append('avance\n')
                x--
        elif (x < 0):
            movement.append('gauche\n')
            while (x > 0):
                movement.append('avance\n')
                x++
        return (movement)
