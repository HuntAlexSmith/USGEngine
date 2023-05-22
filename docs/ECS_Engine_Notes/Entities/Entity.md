One things about entities that I am a bit confused about it identification for the entities. Looks like my best bet would be to set up some module that can generate a unique id for each Entity? This id could then be used to find the components that each entity is using.

Going to use the very simple identification system of counting up from zero and keeping track of ID's that can be re-used. Since I am not expecting to make this engine networked, iterating up from zero is an easy way to do it. Will need to probably create a base class of IDSystem so that if I want to try something like a GUID, I can.

Info on how the IDSystem will be set up will be found [Here](IDSystem)
