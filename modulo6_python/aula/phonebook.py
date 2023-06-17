import cs50
import csv

def main():

    file= open("phonebook.csv","a")

    name=cs50.get_string("Name: ")
    number=cs50.get_string("Phone: ")

    writer=csv.writer(file)

    writer.writerow([name,number])

    file.close()

main()