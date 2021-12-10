#!/usr/bin/ruby

availableInitiators = Array['(', '[', '{', '<']
correctMatches = Hash['(' => ')', '[' => ']', '{' => '}', '<' => '>']
scoreWhenIllegal = Hash[')' => 3, ']' => 57, '}' => 1197, '>' => 25137]
sum = 0

input = Array.new
file = File.open("syntaxScoringInput.txt", "r")
while !file.eof?
  element = file.readline
  input.append(element)
end

input.each do |line|
  initiators = Array.new
  line.each_char do |c|
    if availableInitiators.include? c
      initiators.push(c)
    elsif c != correctMatches[initiators.last]
      sum += scoreWhenIllegal[c].to_i
      break
    else
      initiators.pop
    end
  end
end

puts sum
