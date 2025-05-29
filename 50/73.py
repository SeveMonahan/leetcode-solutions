class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        num_columns = len(matrix)
        num_rows = len(matrix[0])

        should_zero_zeroth_row = False

        for i in range(0, num_columns):
            if matrix[i][0] == 0:
                should_zero_zeroth_row = True
            for j in range(1, num_rows):
                if matrix [i][j] == 0:
                    ## print(f'i is {i}, j is {j}')
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for j in range(1, num_rows):
            ## print(f'Clearing row {j}')
            if(matrix[0][j] == 0):
                for i in range(0, num_columns):
                    matrix [i][j] = 0

        for i in range(0, num_columns):
            if(matrix[i][0] == 0):
                ## print(f'Clearing Column {i}')
                for j in range(0, num_rows):
                    matrix[i][j] = 0
        
        if(should_zero_zeroth_row):
            ## print(f'Clear Row 0')
            for i in range(0, num_columns):
                matrix[i][0] = 0

        
