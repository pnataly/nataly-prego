class Timer

  def initialize()
    @seconds = 0
    @minutes = 0
    @hours = 0
  end

  def seconds=seconds
    @seconds=seconds
    if(@seconds > 60)
      while(@seconds>60)
        @seconds -= 60
        @minutes += 1
      end
    end
    if(@minutes > 60)
      while(@minutes >60)
        @hours += 1
        @minutes -= 60
      end
    end
  end

  def seconds
    return @seconds
  end

  def time_string
    if(@seconds<10)
      @seconds = "0#{@seconds}"
    end
    if(@minutes<10)
      @minutes = "0#{@minutes}"
    end
    if(@hours<10)
      @hours = "0#{@hours}"
    end
      return "#{@hours}:#{@minutes}:#{@seconds}"
  end

end
