declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
bb1:
  %r159 = add i32 0, 0
  %r160 = add i32 0, 0
  %r161 = add i32 0, 0
  %r162 = add i32 0, 0
  %r163 = add i32 0, 0
  call void @_sysy_starttime(i32 3)
  %r164 = add i32 0, 0
  %r165 = add i32 0, 0
  %r102 = alloca [ 10 x i32 ]
  %r166 = add i32 0, 0
  %r167 = add i32 0, 0
  br label %bb_while_5_9_cond

bb_while_5_9_cond:
  %r168 = phi i32 [ %r167, %bb1 ], [ %r169, %bb_while_5_9_whilestms ]
  %r104 = icmp slt i32 %r168, 10
  br i1 %r104, label %bb_while_5_9_whilestms, label %bb_while_5_9_bre

bb_while_5_9_whilestms:
  %r106 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r168
  %r108 = add i32 %r168, 1
  store i32 %r108, i32* %r106
  %r110 = add i32 %r168, 1
  %r169 = add i32 %r110, 0
  br label %bb_while_5_9_cond

bb_while_5_9_bre:
  %r170 = add i32 10, 0
  %r116 = call i32 @getint()
  %r171 = add i32 %r116, 0
  %r118 = sub i32 %r170, 1
  %r172 = add i32 %r118, 0
  %r173 = add i32 0, 0
  %r121 = add i32 %r172, %r173
  %r122 = sdiv i32 %r121, 2
  %r174 = add i32 %r122, 0
  br label %bb_while_5_24_cond

bb_while_5_24_cond:
  %r175 = phi i32 [ %r173, %bb_while_5_9_bre ], [ %r181, %bb_if_9_27_end ]
  %r176 = phi i32 [ %r172, %bb_while_5_9_bre ], [ %r182, %bb_if_9_27_end ]
  %r177 = phi i32 [ %r174, %bb_while_5_9_bre ], [ %r178, %bb_if_9_27_end ]
  %r124 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r177
  %r125 = load i32, i32* %r124
  %r127 = icmp ne i32 %r125, %r171
  br i1 %r127, label %bb27_24_next, label %bb_while_5_24_bre

bb27_24_next:
  %r130 = icmp slt i32 %r175, %r176
  br i1 %r130, label %bb_while_5_24_whilestms, label %bb_while_5_24_bre

bb_while_5_24_whilestms:
  %r133 = add i32 %r176, %r175
  %r134 = sdiv i32 %r133, 2
  %r178 = add i32 %r134, 0
  %r137 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r178
  %r138 = load i32, i32* %r137
  %r139 = icmp slt i32 %r171, %r138
  br i1 %r139, label %bb_if_9_27_true, label %bb_if_9_27_false

bb_if_9_27_true:
  %r141 = sub i32 %r178, 1
  %r179 = add i32 %r141, 0
  br label %bb_if_9_27_end

bb_if_9_27_false:
  %r143 = add i32 %r178, 1
  %r180 = add i32 %r143, 0
  br label %bb_if_9_27_end

bb_if_9_27_end:
  %r181 = phi i32 [ %r175, %bb_if_9_27_true ], [ %r180, %bb_if_9_27_false ]
  %r182 = phi i32 [ %r179, %bb_if_9_27_true ], [ %r176, %bb_if_9_27_false ]
  br label %bb_while_5_24_cond

bb_while_5_24_bre:
  %r146 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r177
  %r147 = load i32, i32* %r146
  %r148 = icmp eq i32 %r171, %r147
  br i1 %r148, label %bb_if_5_37_true, label %bb_if_5_37_false

bb_if_5_37_true:
  call void @putint(i32 %r171)
  br label %bb_if_5_37_end

bb_if_5_37_false:
  %r183 = add i32 0, 0
  call void @putint(i32 %r183)
  br label %bb_if_5_37_end

bb_if_5_37_end:
  %r184 = phi i32 [ %r171, %bb_if_5_37_true ], [ %r183, %bb_if_5_37_false ]
  %r185 = add i32 10, 0
  call void @putch(i32 %r185)
  call void @_sysy_stoptime(i32 49)
  ret i32 0
}

