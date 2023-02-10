CC := g++
EXE := ./exe

.PYHON:	buildItem7, buildItem9, buildItem9, buildItem10, buildItem11, buildItem12, buildItem15, buildItem16, buildItem17, buildTest

buildItem7: Item7-Distinguish_initial.cpp
	@$(CC) $^ -o $(EXE)/Item7.exe

buildItem9: Item9-Prefer_alias_declarations_to_typedefs.cpp
	@$(CC) $^ -o $(EXE)/Item9.exe

buildItem10: Item10-Prefer_scoped_enums_to_unscoped_enums.cpp
	@$(CC) $^ -o $(EXE)/Item10.exe

buildItem11: Item11-Prefer_deleted_functions_to_private_undefined_ones.cpp
	@$(CC) $^ -o $(EXE)/Item11.exe

buildItem12: Item12-Declare_overriding_functions_override.cpp
	@$(CC) $^ -o $(EXE)/Item12.exe

buildItem15: Item15-Use_constexpr_whenever_possible.cpp
	@$(CC) $^ -o $(EXE)/Item15.exe

buildItem16: Item16_Make_cons_member_functions_thread_safe.cpp
	@$(CC) $^ -o $(EXE)/Item16.exe

buildItem17: Item17-Understand_special_member_function_generation.cpp
	@$(CC) $^ -o $(EXE)/Item17.exe

buildTest: rightTest.cpp
	@$(CC) $^ -o $(EXE)/rightTest.exe -fno-elide-constructors