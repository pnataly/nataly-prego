class Book
    def initialize(title="")
        @title = title
    end

    def title=title
        #@title = title.capitalize
        exception = ['and', 'a', 'an', 'in', 'the', 'of']
        title = title.split
        title.each do |x|
            if (!exception.include?(x) or x == title[0])    
                x.capitalize!
            end
        end
        
        title = title.join(" ")
        @title = title
    end

    def title
        return @title
    end

end
