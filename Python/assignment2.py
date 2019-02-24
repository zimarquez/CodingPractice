"""
Ismael Marquez, im6549
"""
def lyrics_to_frequency(lyrics):
    """ this functin takes a list of the song lyrics
    and returns a dictionary with words as its keys 
    and frequency as its values"""
    #write your code here
    lyrics_dict = {}
    for word in lyrics:
        if word in lyrics_dict:
            lyrics_dict[word] += 1
        else:
            lyrics_dict[word] = 1
    return lyrics_dict  
    
def most_common_word(dictWords):
    """This function takes a dictionary of word frequency
    and returns the most common word in the song and its frequency packed in a tuple
    example: (['word1'], 15)
    """
    #write your code here
    most_common_val = -1
    result = ('NULL', most_common_val)
    for word in dictWords:
        if dictWords[word] > most_common_val:
            most_common_val = dictWords[word]
            result = (word, dictWords[word])
    return result
  
def words_only_once(dictWords):
    """This function takes a dictionary of word frequency
    and returns a list of tuples of words that occur only once in the song
    example: [(['word1'], 1),(['word2'],1),...] 
    """
    #write your code here
    one_word_occurences = []
    for word in dictWords:
        if dictWords[word] == 1:
            one_word_occurences.append((word, dictWords[word]))
    return one_word_occurences

def words_with_minimum_freq(dictWords, minTimes):
    """This function takes a dictionary of word frequency 
    and returns a list of tuples of words and their frequencies
    the words returned should have frequencies higher than the 
    "minTimes" argument"""
    #write your code here
    one_word_occurences = []
    for word in dictWords:
        if dictWords[word] >= minTimes:
            one_word_occurences.append((word, dictWords[word]))
    return one_word_occurences    

#Sample run:
#do not run this part until you finish developing each function seperately
def main():
    songDict=lyrics_to_frequency(she_loves_you)
    topWord=most_common_word(songDict)
    print(topWord)
    #finding the least common word
    leastWords=words_only_once(songDict)
    print(leastWords)
    #finding words that occur at least 5 times
    mostWords=words_with_minimum_freq(songDict,5)
    print(mostWords)

    


if __name__ == '__main__':
    main()