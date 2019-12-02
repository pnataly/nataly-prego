#write your code here

def add(a,b)
    return a+b
end

def subtract(a,b)
    return a-b
end

def sum arr
    count = 0
    arr.each do |num|
        count += num
    end
    return count
end

def multiply(a,b)
    return a*b
end

def power(a,b)
    return a**b
end