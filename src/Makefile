EXECUTABLE = lab
SOURCES = main.cc \
          data/mnist_dataset.cc \
          neural_network/layer/input_layer.cc \
          neural_network/layer/layer.cc \
          neural_network/layer/neuron_layer.cc \
          neural_network/layer/output_layer.cc \
          neural_network/node/input_node.cc \
          neural_network/node/neuron_node.cc \
          neural_network/node/neuron_node_synapse.cc \
          neural_network/node/node.cc \
          neural_network/node/output_node.cc \
          neural_network/neural_network.cc \

CXX = g++
CXXFLAGS = -c -I . -Wall
LDXXFLAGS =

OBJDIR = obj
OBJECTS = $(SOURCES:%.cc=$(OBJDIR)/%.o)
DEPS = $(SOURCES:%.cc=$(OBJDIR)/%.d)

DEP_FILTER := 'BEGIN { patt = "^"n"\\.o[ \t]*:"; repl = r"/"n".o "r"/"n".d:"; } { gsub(patt, repl); print; }'

build: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE).exe
	rm -r -f obj

$(OBJDIR)/%.d: %.cc
	@echo making depends for $<
	@mkdir -p $(@D)
	@$(CXX) -c -MM $(CXXFLAGS) $< | \
            gawk -v n=$(notdir $(basename $@)) \
                 -v r=$(patsubst %/,%,$(dir $@)) $(DEP_FILTER) > $@

$(OBJDIR)/%.o: %.cc
	@echo compiling $<
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(EXECUTABLE): $(OBJECTS)
	@echo linking $@
	@mkdir -p $(@D)
	@$(CXX) $(LDXXFLAGS) -o $@ $^

-include $(DEPS)
