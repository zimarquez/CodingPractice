import csv
#[gender, race/ethnicity, parent education level, lunch, test prep course, math score, reading score, writing score]
csv_file = open('../datasets/StudentsPerformance.csv')
csv_reader = csv.reader(csv_file)

#rownum = 0
#for row in csv_reader:
#    if rownum == 0:
#        header = row
#print(header) #prints first row of data
#print(header[0]) # prints first element of the specified person


def CountData(data, category) :
    
    next(csv_reader)    #skip the first row
    for dataRow in csv_reader:
        elementString = dataRow[category]
        data[elementString][0] += 1

def printCount(data) :
    for element in data:
        print(element, data[element][0])

# gender data
genderData = {'female': [0], 'male': [0]}
CountData(genderData,0)
printCount(genderData)

# race data
raceData = {'female': [0], 'male': [0]}
CountData(genderData,0)
printCount(genderData)

# parent education level data

# lunch data

# test prep course data

# math score data

# reading score data

# writing score data
    
def main():
    # TODO
    print('test')
    
if __name__ == '__main__': main()