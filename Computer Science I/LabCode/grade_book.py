def main():
    fin=open('grade_book.txt',"r")
    categories = fin.readline()
    categories=categories.replace("\n","")
    categ_list=categories.split(",")
    
    # use a dictionary of dictionaries
    # the key of the outer dictionary: the items in the studentID column
    # the value of the outer dictionary: an inner dictionary corresponding to each studentID
    #                                    for example, the inner dictionary corresponding to the studentID 1  is as the following
    #                                    {"name":"lucy", "English":70, "Math":80, "CS":90, "Chinese":67, "Spanish":89, "History":90} 
    # So, your output dictionary should be something like the following:
    # {"1": {"name":"lucy", "English":70, "Math":80, "CS":90, "Chinese":67, "Spanish":89, "History":90},
    # "2": {"name":"jeff", "English":89, "Math":90, "CS":67, "Chinese":67, "Spanish":89, "History":90},
    # "3":....... }. Here, only two elements of the dictionary are shown. 
    # jeff,89,90,67,89,89,90

    dict = {}                           #initialize accumulator grade_dict
    for line in fin:
        # all the code here process one single line    #
        line=line.replace('\n',"")
        line_lst=line.split(',')#
        #dict = {} 
        dict[line_lst[0]] = {"Name":line_lst[1],"English":line_lst[2],"Math":line_lst[3],"CS":line_lst[4],"Chinese":line_lst[5],"Spanish":line_lst[6],"History":line_lst[7]}                                               
        #
                                                       #
        # until now, finish processing the current line#
    #after the for loop, finish processing all the lines
    fin.close()
    acc = 0
    for i,v in dict.items():
        for ii,vv in v.items():
            if ii == "CS":
                acc = acc + int(vv)

    print(acc/int(len(dict)))
    
    #now, calculate the average grade of CS and print it out
 
    dict["50"] = {"Name":"bill_clinton","English":60,"Math":60,"CS":60,"Chinese":60,"Spanish":60,"History":60}
    #need to add a student with studentID 50, name bill_cliton, English 60, Math 60,
    #CS 60, Chinese 60, Spanish 60, History 60 to the dictionary
    #print(dict)
    dict["7"]["History"] = 95
    print(dict)
    #need to update the history grade of the student with studentID 7 to be 95


    
 
    

main()
    
    
    
