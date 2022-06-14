module dimmer1(clock_50, reset, increaseDuty, decreaseDuty, test, LED);

	input clock_50;			//50 MHz clock on DE10-lite		
	input reset;			//hard reset (brightness <-- 0)		 
	input increaseDuty;		//key[0] raises duty cycle by one		
	input decreaseDuty;		//key[1] lowers duty cycle by one	
	output LED;			//ardinoIO[0]
		
	reg buttonpressed;				
	reg nextbuttonpressed;			
	reg [4:0] brightness;		//spectrum of 16 brightness values	
	reg [4:0] nextbrightness;	//next brightness state (brightness value +/- 1)
	reg [17:0] cyclecounter;	//counts to 250000 to update LED brightness	
	reg [25:0] upTimer;		//timer counts from 0 to 2^26 to track if key[0] is being pressed
	reg [25:0] downTimer;	        //timer counts from 0 to 2^26 to track if key[1] is being pressed	
	
//at every clock edge
	always @(upTimer or downTimer) begin
//check if key[0] is begin pressed		
		if (!increaseDuty && (upTimer == 0) && buttonpressed) begin
			nextbrightness <= (brightness < 4'd15) ? brightness + 4'b1 : brightness;
		end
//check if key[1] is being pressed
		else if (!decreaseDuty && (downTimer == 0) && buttonpressed) begin
			nextbrightness <= (brightness > 0) ? brightness - 4'b1 : brightness;
		end
//otherwise remain at current state if no button is being pressed
		else begin
			nextbrightness <= brightness;
		end
	end
//at every clock edge
	always @(posedge clock_50 or negedge reset) begin
//check status of reset switch		
		if (reset == 0) begin
			cyclecounter <= 0;
			brightness <= 0;
			buttonpressed <= 0;
			upTimer <= 0;
			downTimer <= 0;	
		end
		else begin
//if reset not engaged, go to next state	
			brightness <= nextbrightness;
			buttonpressed <= nextbuttonpressed;
//cycle counter incremented to act as timer
			cyclecounter <= cyclecounter + 13'b1;
//cycle counter resets to 0 and starts counting again			
			if (cyclecounter >= 250000) begin
				cyclecounter <= 0;
			end
//up timer resets to 0 and starts counting again
			if (upTimer >= 50000000 || (increaseDuty == 1)) begin
				upTimer <= 0;
			end
			else begin
				upTimer <= upTimer + 18'b1;
			end
			
			
			if (downTimer >= (50000000/level) || (decreaseDuty == 1)) begin
				downTimer <= 0;
			end
			else begin
				downTimer <= downTimer + 18'b1;
			end
		end
	end
	
	always @(negedge increaseDuty or negedge decreaseDuty) begin		
		
		if (increaseDuty == 0) begin
			nextbuttonpressed <= 1;
		end
		else if (decreaseDuty == 0) begin
			nextbuttonpressed <= 1;
		end
		else begin
			nextbuttonpressed <= 0;
		end
	end
	

assign LED = (cyclecounter < brightness*(15625) ? 1'b1 : 1'b0;

endmodule
