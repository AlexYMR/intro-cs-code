def transpose(mat):
    dict = {}
    for i in range(len(mat)):
        for ii in range(len(mat[i])):
            if not ii in dict:
                dict[ii] = [mat[i][ii]]
            else:
                dict[ii].append(mat[i][ii])
            
    tranMat = dict.values()
    print(tranMat)
    return tranMat

def main():
    transpose([[1,2,3],[4,5,6],[7,8,9]])

main()
