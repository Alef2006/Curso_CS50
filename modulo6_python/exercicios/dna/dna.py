import csv
import sys




def main(n):

    STR={}
    dictDataBases={}

    if len(n)<2:
        print("Falta argumentos na linha de comando")
        sys.exit(1)
  
    dataBases=n[1]
    sequence=n[2]
    
    #with open(dataBases,"r") as file:
     #next(reader)

    fileDataBases=list(csv.reader(open(dataBases,"r"))) 
    fileSequence=list(csv.reader(open(sequence,"r"),delimiter=","      ))
    
    #alimentando lista de STR que veio do dataBases para contabilizar dados da amostra de DNA

    for i in range(len(fileDataBases[0])):
          if i>0:
             #print(fileDataBases[0][i])
             STR[fileDataBases[0][i]]=0
    
    #criando um dicionario com as informacoes do dataBases para uma futura comparacão
    listDataBases=list(fileDataBases)
    for i in range(len(listDataBases)):
        if i>0:
           dictDataBases[listDataBases[i][0]]=[]

    listKeys=list(dictDataBases.keys())
    for i in range(len(listKeys)):
              values=listDataBases[i+1][1:len(STR.keys())+1]
              dictDataBases[listKeys[i]]=values

        


    

            
  
   
        
    #Contando os strs do arquivo sequence
    amostraList=",".join(fileSequence[0])
    for str in STR.keys():
       j=0
       max_strand=-1
       cur_max=0
       #result=0
       while j < len(amostraList):
         window= amostraList[j:j+len(str)] 
         if window==str:
            cur_max+=1
            max_strand=max(max_strand,cur_max)
            j+=len(str)
         else:
             cur_max=0
             j+=1  

       STR[str]=max_strand 

    

    amostraCount=[]
    listKeysSTR=list(STR.keys())
    for i in range(len(listKeysSTR)):
        amostraCount.insert(i,STR[listKeysSTR[i]])
    
      
    
  #Comparção final(resultado do algoritmo)
      
    test2=None
    result=None
    
    for i in range(len(listKeys)):
        test=dictDataBases[listKeys[i]]
        test1=list(map(int,test))
        if test1==amostraCount:
            test2=test1
            result=listKeys[i]
        
    
    if test2==amostraCount:
        print(result)
    else:
        print("Sem correspondencia")

 
     
   
    
   
main(sys.argv)