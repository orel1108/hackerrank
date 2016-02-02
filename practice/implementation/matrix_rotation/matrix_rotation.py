# Enter your code here. Read input from STDIN. Print output to STDOUT
def transfrom(i_matrix, i_m, i_n):
    res = []
    num_rows = i_m
    num_cols = i_n
    min_row = 0
    max_row = num_rows - 1
    min_col = 0
    max_col = num_cols - 1
    while min_row <= max_row and min_col <= max_col:
        tmp = []
        for ROW_NUM in range(min_row, max_row):
            tmp.append(i_matrix[ROW_NUM][min_col])
        for COL_NUM in range(min_col, max_col):
            tmp.append(i_matrix[max_row][COL_NUM])
        for ROW_NUM in range(max_row, min_row, -1):
            tmp.append(i_matrix[ROW_NUM][max_col])
        for COL_NUM in range(max_col, min_col, -1):
            tmp.append(i_matrix[min_row][COL_NUM])
        res.append([VAL for VAL in tmp])
        min_row += 1
        max_row -= 1
        min_col += 1
        max_col -= 1
    return res

def inverse_transform(i_trans_matrix, i_m, i_n):
    res = [[0 for _ in range(i_n)] for __ in range(i_m)]
    num_rows = i_m
    num_cols = i_n
    min_row = 0
    max_row = num_rows - 1
    min_col = 0
    max_col = num_cols - 1
    for LINE in i_trans_matrix:
        cnt = 0
        for ROW_NUM in range(min_row, max_row):
            res[ROW_NUM][min_col] = LINE[cnt]
            cnt += 1
        for COL_NUM in range(min_col, max_col):
            res[max_row][COL_NUM] = LINE[cnt]
            cnt += 1
        for ROW_NUM in range(max_row, min_row, -1):
            res[ROW_NUM][max_col] = LINE[cnt]
            cnt += 1
        for COL_NUM in range(max_col, min_col, -1):
            res[min_row][COL_NUM] = LINE[cnt]
            cnt += 1
        min_row += 1
        max_row -= 1
        min_col += 1
        max_col -= 1
    return res

def rotate(i_trans_matrix, i_r):
    rotated = []
    for CNT in range(len(i_trans_matrix)):
        L = len(i_trans_matrix[CNT])
        r = i_r % L
        #print i_trans_matrix[CNT]
        rotated.append([VAL for VAL in i_trans_matrix[CNT][L - r:] + i_trans_matrix[CNT][:L - r]])
        #print rotated[-1]
        #assert L == len(rotated[-1])
    return rotated

m, n, r = map(int, raw_input().split())
matrix = []
for _ in range(m):
    matrix.append(map(int, raw_input().split()))
    
t = transfrom(matrix, m, n)
rot = rotate(t, r)
res = inverse_transform(rot, m , n)
for LINE in res:
    for VAL in LINE:
        print VAL,
    print

