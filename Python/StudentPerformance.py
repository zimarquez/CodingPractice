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

##########################################
###   Start of function declarations   ###
##########################################
def CountBackgroundData(data, category) :
    next(csv_reader)    # ignores the title (i.e. the first element in the column)
    for dataRow in csv_reader:
        elementString = dataRow[category]
        data[elementString][0] += 1

def CountTestResults(data, category) :
    next(csv_reader)    # ignores the title (i.e. the first element in the column)
    for dataRow in csv_reader:
        score = (int)(dataRow[category])
        if score == 100 :
            data['100'][0] += 1
        elif (score >= 90 and score <= 99) :
            data['90-99'][0] += 1
        elif (score >= 80 and score <= 89) :
            data['80-89'][0] += 1
        elif (score >= 70 and score <= 79) :
            data['70-79'][0] += 1
        elif (score >= 0 and score <= 69) :
            data['0-69'][0] += 1
        
def printCount(data) :
    for element in data:
        print(element, ':', data[element][0])
    
    print('**PASS**\n')

# lunch data

# test prep course data

# math score data

# reading score data

# writing score data
    
def main():
    
    ### Gather background data ###
    # gender data
    genderData = {'female': [0], 'male': [0]}
    CountBackgroundData(genderData,0)
    printCount(genderData)
    
    # race data
    csv_file.seek(0)    # reset to start of file
    raceData = {'group A': [0], 'group B': [0], 'group C': [0], 'group D': [0], 'group E': [0]}
    CountBackgroundData(raceData,1)
    printCount(raceData)
    
    # parent education level data
    csv_file.seek(0)
    parentData = {'some high school': [0], 'high school': [0], 'some college': [0], 
                'associate\'s degree': [0], 'bachelor\'s degree': [0], 'master\'s degree': [0]}
    CountBackgroundData(parentData,2)
    printCount(parentData)
    
    # lunch data
    csv_file.seek(0)
    lunchData = {'standard': [0], 'free/reduced': [0]}
    CountBackgroundData(lunchData,3)
    printCount(lunchData)
    
    # test preparation data
    csv_file.seek(0)
    preparationData = {'completed': [0], 'none': [0]}
    CountBackgroundData(preparationData,4)
    printCount(preparationData)
    
    ### Gather test data ###
    # math results
    csv_file.seek(0)
    print('Math Results:')
    mathData = {'100': [0], '90-99': [0], '80-89': [0], '70-79': [0], '0-69': [0]}
    CountTestResults(mathData,5)
    printCount(mathData)

    # reading results
    csv_file.seek(0)
    print('Reading Results:')
    readingData = {'100': [0], '90-99': [0], '80-89': [0], '70-79': [0], '0-69': [0]}
    CountTestResults(readingData,6)
    printCount(readingData)

    # writing results
    csv_file.seek(0)
    print('Writing Results:')
    writingData = {'100': [0], '90-99': [0], '80-89': [0], '70-79': [0], '0-69': [0]}
    CountTestResults(writingData,7)
    printCount(writingData)
    
    
    
if __name__ == '__main__': main()