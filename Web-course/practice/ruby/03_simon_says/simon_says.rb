#write your code here

def echo(str)
    return str
end

def shout(str)
    return str.upcase
end

def repeat(str, num=2)
    s= "#{str} " * num
    return s[0...-1]
end

def start_of_word(s, num)
    return s[0,num]
end

def first_word(s)
    arr = s.split
    return arr[0]
end

def titleize(s)
    s=s.capitalize
    arr=s.split
    little_words = ["the", "over", "and"]
    output =[]
    arr.each do |x|
        if(little_words.include?(x))
            output.push(x)
        else 
            output.push(x.capitalize)
        end
    end
    return output.join(" ")
end