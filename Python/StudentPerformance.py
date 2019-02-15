import csv
#[gender, race/ethnicity, parent education level, lunch, test prep course, math score, reading score, writing score]
csv_file = open('../students-performance-in-exams/StudentsPerformance.csv')
csv_reader = csv.reader(csv_file)

#rownum = 0
#for row in csv_reader:
#    if rownum == 0:
#        header = row
#print(header) #prints first row of data
#print(header[0]) # prints first element of the specified person

# gender data
genderData = {'Females': [0], 'Males': [0]}
numFemales = 0;
for row in csv_reader:
    header = row
    if (header[0] == 'female') :
        genderData['Females'][0] += 1
    elif (header[0] == 'male') :
        genderData['Males'][0] += 1

print('Females:', genderData['Females'][0])
print('Males:', genderData['Males'][0])

# race/ethnicity data

# parent education level data

# lunch data

# test prep course data

# math score data

# reading score data

# writing score data