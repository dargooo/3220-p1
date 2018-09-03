# Project 1 

This is brief description for project 1. 

* Some very simple code for ruby beginners.
* Some description about basic usage of ruby.
* A program with 2 classes that updates a searching list of movies and then stores the list into a file.


### Quick start

> Clone/Download the solution then run `main.rb`

```

# Download Project1_Wang_Dargo.zip file from canvas
# Unpack the zip file

# For Mac OSX
$ unzip -a Project1_Wang_Dargo.zip
$ ruby main.rb

```

# Table of Contents

* [License](#license)
* [Author](#author)



#### API Intro

SearchController class provides functions needed for updating the searching list.

```
class SearchController

    attr_accessor :searchSuggestionList

    def initialize(search_list = [])

    def showList()

    def updateList(movie_name)

    def saveListToFile()

end
```

 `updateList`  function is the major one to handle the program. It inserts the new name in the front of the list.

```
def updateList(movie_name)
    new_list = [movie_name]
    @search_list.each do |movie|
        if movie.upcase != movie_name.upcase
            new_list.push(movie)
        end
    end
    @search_list = new_list
end
```

`saveListToFile`  function writes the updated list onto a "data.txt" file after the update of searching list is finished.

```
def saveListToFile()
    newFile = File.new("data.txt", "w+")
    if newFile
        newFile.puts(@search_list)
    end
end
```

___

#### Implementation 

The program is using each iterator on array, in order to compare each word in the existing list to the new word, and then push it in the end of the new list.

___

#### Program Time Complexity

The program runs with O(n2) time complexity.

___

#### Result of Sample Test Case

"Date.txt" file is updated by main.rb program execution. 

___

#### License
 [Auburn University](/LICENSE)

___

## Author
 [Dargo Wang](/LICENSE)
