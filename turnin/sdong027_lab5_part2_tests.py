tests = [ {'description': 'PINA: 0x00 => PORTC: 7',	# TESTS WRITTEN FOR NON-PULLUP
	'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 2}],
	'expected': [('PORTC', 7)],
	}, 
	{'description': 'PINA: 0x01 => PORTC: 8',
	'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2}],
	'expected': [('PORTC', 8)],
	},
	{'description': 'PINA: 0x01 => PORTC: 8',
	'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2}],
	'expected': [('PORTC', 8)],
	},
	{'description': 'PINA: 0x00 => PORTC: 8',
	'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 2}],
	'expected': [('PORTC', 8)],
	},
	{'description': 'PINA: 0x01 => PORTC: 9',
	'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2}],
	'expected': [('PORTC', 9)],
	},
	{'description': 'PINA: 0x00 => PORTC: 9',
	'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 2}],
	'expected': [('PORTC', 9)],
	},
	{'description': 'PINA: 0x02 => PORTC: 8',
	'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 2}],
	'expected': [('PORTC', 8)],
	},
	{'description': 'PINA: 0x03 => PORTC: 0',
	'steps': [{'inputs': [('PINA', 0x03)], 'iterations': 2}],
	'expected': [('PORTC', 0)],
	},
	{'description': 'PINA: 0x02 => PORTC: 0',
	'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 2}],
	'expected': [('PORTC', 0)],
	},
	{'description': 'PINA: 0x01 => PORTC: 1',
	'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2}],
	'expected': [('PORTC', 1)],
	},
	]
