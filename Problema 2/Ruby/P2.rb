# list_node
class ListNode
    attr_accessor :val, :next
    def initialize(val = 0, next_node = nil)
      @val = val
      @next = next_node
    end
end
  
  def add_two_numbers(l1, l2)
    auxiliar_node = ListNode.new
    actual_node = auxiliar_node
    tens = 0

    while l1 || l2 || tens > 0
      value1 = l1 ? l1.val : 0
      value2 = l2 ? l2.val : 0
      
      sum = value1 + value2 + tens
      tens = sum / 10
      
      actual_node.next = ListNode.new(sum % 10)
      actual_node = actual_node.next
  
      l1 = l1.next if l1
      l2 = l2.next if l2
    end
  
     auxiliar_node.next
  end