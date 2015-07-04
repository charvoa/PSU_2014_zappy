class MoveClass():

    """ MoveClass a class that get the best movement for an AI"""

    def getMovements(self, target):
        if (target == 0):
            return (0, 0)
        y = 1
        x = 0
        res = 0
        while (res < target):
            res = res + (y * 2)
            y += 1
        y -= 1
        if (res - y > target):
            res = res - (y * 2)
            y -= 1
            x = target - res
        else:
            x = target - res
######
        # while (y > 0):
        #     movement.append('avance\n')
        #     y -= 1
        # if (x > 0):
        #     movement.append('droite\n')
        #     while (x > 0):
        #         movement.append('avance\n')
        #         x -= 1
        # elif (x < 0):
        #     movement.append('gauche\n')
        #     while (x > 0):
        #         movement.append('avance\n')
        #         x += 1
        return x, y
