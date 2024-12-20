# TestP2.rb
require_relative 'P2'
require 'test/unit'

# Métodos auxiliares para pruebas
def create_list(array)
  return nil if array.empty?
  auxiliar_node = ListNode.new
  actual_node = auxiliar_node
  array.each do |val|
    actual_node.next = ListNode.new(val)
    actual_node = actual_node.next
  end
  auxiliar_node.next
end

def list_to_array(head)
  result = []
  while head
    result << head.val
    head = head.next
  end
  result
end

class TestAddTwoNumbers < Test::Unit::TestCase
  def setup
    @test_cases = [
      {l1: [2,4,3], l2: [5,6,4], expected: [7,0,8], description: '342 + 465 = 807'},
      {l1: [0], l2: [0], expected: [0], description: '0 + 0 = 0'},
      {l1: [9,9,9,9,9,9,9], l2: [9,9,9,9], expected: [8,9,9,9,0,0,0,1], description: '9999999 + 9999 = 10009998'},
      {l1: [1,8], l2: [0], expected: [1,8], description: '81 + 0 = 81'},
      {l1: [5], l2: [5], expected: [0,1], description: '5 + 5 = 10'}
    ]
  end

  def test_add_two_numbers
    @test_cases.each do |tc|
      l1 = create_list(tc[:l1])
      l2 = create_list(tc[:l2])
      result = add_two_numbers(l1, l2)
      assert_equal(tc[:expected], list_to_array(result), "Failed for case: #{tc[:description]}")
    end
  end
end