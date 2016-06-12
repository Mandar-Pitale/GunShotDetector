.PHONY: clean All

All:
	@echo "----------Building project:[ GDS - Debug ]----------"
	@cd "GDS" && $(MAKE) -f  "GDS.mk"
clean:
	@echo "----------Cleaning project:[ GDS - Debug ]----------"
	@cd "GDS" && $(MAKE) -f  "GDS.mk" clean
