#include <stdio.h>
#include <string.h>

int main()
{
    char character;
    int i, j, x, rows, columns, total, rowIndex, colIndex, increment, direction;
    scanf("%d %d", &rows, &columns);
    char map[columns][rows + 1];
    rowIndex = 0;
    colIndex = 0;
    x = 0;

    for (i = 0; i < columns; i++)
        scanf("%s", map[i]);

    total = rows * columns;

    for (increment = 1; increment <= total;)
    {
        if (map[rowIndex][colIndex] == '>')
        {
            colIndex++;
            increment++;
            direction = 1;
            if (colIndex >= rows)
                break;
        }
        else if (map[rowIndex][colIndex] == 'v')
        {
            rowIndex++;
            increment++;
            direction = 2;
            if (rowIndex >= columns)
                break;
        }
        else if (map[rowIndex][colIndex] == '<')
        {
            colIndex--;
            increment++;
            direction = 3;
            if (colIndex < 0)
                break;
        }
        else if (map[rowIndex][colIndex] == '^')
        {
            rowIndex--;
            increment++;
            direction = 4;
            if (rowIndex < 0)
                break;
        }
        else if (map[rowIndex][colIndex] == '*')
        {
            increment = 1000;
            break;
        }
        else if (map[rowIndex][colIndex] == '.')
        {
            if (direction == 1)
            {
                colIndex++;
                increment++;
                if (colIndex >= rows)
                    break;
            }
            else if (direction == 2)
            {
                rowIndex++;
                increment++;
                if (rowIndex >= columns)
                    break;
            }
            else if (direction == 3)
            {
                colIndex--;
                increment++;
                if (colIndex < 0)
                    break;
            }
            else if (direction == 4)
            {
                rowIndex--;
                increment++;
                if (rowIndex < 0)
                    break;
            }
        }
    }

    if (increment == 1000)
        printf("*\n");
    else
        printf("!\n");

    return 0;
}