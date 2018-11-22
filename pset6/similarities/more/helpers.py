from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""
    martix = [[0 for i in range(len(b) + 1)] for j in range(len(a) + 1)]

    # Base case
    martix[0][0] = (0, None)

    for i in range(1, len(martix)):
        martix[i][0] = (i, Operation.DELETED)

    for j in range(1, len(martix[0])):
        martix[0][j] = (j, Operation.INSERTED)

    for i in range(1, len(martix)):
        for j in range(1, len(martix[0])):
            deleteCost, _ = martix[i - 1][j]
            deleteCost += 1
            insertCost, _ = martix[i][j - 1]
            insertCost += 1
            substiteCost, _ = martix[i - 1][j - 1]
            if i < len(a) + 1 and j < len(b) + 1:
                if a[i - 1] != b[j - 1]:
                    substiteCost += 1

            if deleteCost <= insertCost and deleteCost <= substiteCost:
                martix[i][j] = (deleteCost, Operation.DELETED)
            elif insertCost <= deleteCost and insertCost <= substiteCost:
                martix[i][j] = (insertCost, Operation.INSERTED)
            else:
                martix[i][j] = (substiteCost, Operation.SUBSTITUTED)

    return martix
