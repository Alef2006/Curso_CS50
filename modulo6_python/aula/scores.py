import cs50

def main():

    scores=[]

    for i in range(3):
        scores.append(cs50.get_int("Scores:"))
        
    
    average=sum(scores)/len(scores)
    print(f"Average: {average}")
    """
    #way 1
    average=sum(scores)/len(scores)
    print(f"Average 1: {average}")

    #way 2
    print("Average 2: "+ str(sum(scores)/len(scores)))

    #way 3
    print(f"Average 3:{sum(scores)/len(scores)} ")
    """
    
    
   



main()