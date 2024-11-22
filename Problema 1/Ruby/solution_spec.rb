require_relative 'solution'
require 'json'

RSpec.describe Solution do
  before(:each) do
    @sol = Solution.new
  end

  describe '#remove_nth_from_end' do
    test_data = JSON.parse(File.read('test_data.json'))

    test_data.each do |data|
      it "maneja el caso: #{data['description']}" do
        if data['input'].empty? && data['expected_error'] == 'El número de nodos en la lista debe estar entre 1 y 30'
          expect { @sol.list_to_listnode(data['input']) }.to raise_error(RuntimeError, data['expected_error'])
        else
          head = @sol.list_to_listnode(data['input'])
          n = data['n']

          if data['expected_error']
            expect { @sol.remove_nth_from_end(head, n) }.to raise_error(RuntimeError, data['expected_error'])
          else
            expected_output = data['expected_output']
            new_head = @sol.remove_nth_from_end(head, n)
            actual_output = @sol.listnode_to_list(new_head)

            expect(actual_output).to eq(expected_output)
          end
        end
      end
    end
  end
end
