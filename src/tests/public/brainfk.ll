declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@TAPE_LEN = global i32 65536
@BUFFER_LEN = global i32 32768
@tape = global [ 65536 x i32 ] zeroinitializer
@program = global [ 32768 x i32 ] zeroinitializer
@ptr = global i32 0
define void @read_program( ) {
bb1:
  %r184 = add i32 0, 0
  %r185 = add i32 0, 0
  %r186 = add i32 0, 0
  %r102 = call i32 @getint()
  %r187 = add i32 %r102, 0
  br label %bb_while_3_12_cond

bb_while_3_12_cond:
  %r188 = phi i32 [ %r185, %bb1 ], [ %r189, %bb_while_3_12_whilestms ]
  %r105 = icmp slt i32 %r188, %r187
  br i1 %r105, label %bb_while_3_12_whilestms, label %bb_while_3_12_bre

bb_while_3_12_whilestms:
  %r107 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 %r188
  %r108 = call i32 @getch()
  store i32 %r108, i32* %r107
  %r110 = add i32 %r188, 1
  %r189 = add i32 %r110, 0
  br label %bb_while_3_12_cond

bb_while_3_12_bre:
  %r112 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 %r188
  store i32 0, i32* %r112
  ret void
}

define void @interpret( i32* %r113 ) {
bb2:
  %r193 = add i32 0, 0
  %r194 = add i32 0, 0
  %r195 = add i32 0, 0
  %r196 = add i32 0, 0
  br label %bb_while_3_23_cond

bb_while_3_23_cond:
  %r197 = phi i32 [ %r196, %bb2 ], [ %r214, %bb_if_5_43_end ]
  %r198 = phi i32 [ %r193, %bb2 ], [ %r212, %bb_if_5_43_end ]
  %r199 = phi i32 [ %r194, %bb2 ], [ %r213, %bb_if_5_43_end ]
  %r118 = getelementptr i32, i32* %r113, i32 %r197
  %r119 = load i32, i32* %r118
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %bb_while_3_23_whilestms, label %bb_while_3_23_bre

bb_while_3_23_whilestms:
  %r122 = getelementptr i32, i32* %r113, i32 %r197
  %r123 = load i32, i32* %r122
  %r200 = add i32 %r123, 0
  %r125 = icmp eq i32 %r200, 62
  br i1 %r125, label %bb_if_5_25_true, label %bb_if_5_25_false

bb_if_5_25_true:
  %r126 = load i32, i32* @ptr
  %r127 = add i32 %r126, 1
  store i32 %r127, i32* @ptr
  br label %bb_if_5_25_end

bb_if_5_25_false:
  br label %bb_if_5_25_end

bb_if_5_25_end:
  %r129 = icmp eq i32 %r200, 60
  br i1 %r129, label %bb_if_5_28_true, label %bb_if_5_28_false

bb_if_5_28_true:
  %r130 = load i32, i32* @ptr
  %r131 = sub i32 %r130, 1
  store i32 %r131, i32* @ptr
  br label %bb_if_5_28_end

bb_if_5_28_false:
  br label %bb_if_5_28_end

bb_if_5_28_end:
  %r133 = icmp eq i32 %r200, 43
  br i1 %r133, label %bb_if_5_31_true, label %bb_if_5_31_false

bb_if_5_31_true:
  %r134 = load i32, i32* @ptr
  %r135 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r134
  %r136 = load i32, i32* @ptr
  %r137 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r136
  %r138 = load i32, i32* %r137
  %r139 = add i32 %r138, 1
  store i32 %r139, i32* %r135
  br label %bb_if_5_31_end

bb_if_5_31_false:
  br label %bb_if_5_31_end

bb_if_5_31_end:
  %r141 = icmp eq i32 %r200, 45
  br i1 %r141, label %bb_if_5_34_true, label %bb_if_5_34_false

bb_if_5_34_true:
  %r142 = load i32, i32* @ptr
  %r143 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r142
  %r144 = load i32, i32* @ptr
  %r145 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r144
  %r146 = load i32, i32* %r145
  %r147 = sub i32 %r146, 1
  store i32 %r147, i32* %r143
  br label %bb_if_5_34_end

bb_if_5_34_false:
  br label %bb_if_5_34_end

bb_if_5_34_end:
  %r149 = icmp eq i32 %r200, 46
  br i1 %r149, label %bb_if_5_37_true, label %bb_if_5_37_false

bb_if_5_37_true:
  %r150 = load i32, i32* @ptr
  %r151 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r150
  %r152 = load i32, i32* %r151
  call void @putch(i32 %r152)
  br label %bb_if_5_37_end

bb_if_5_37_false:
  br label %bb_if_5_37_end

bb_if_5_37_end:
  %r154 = icmp eq i32 %r200, 44
  br i1 %r154, label %bb_if_5_40_true, label %bb_if_5_40_false

bb_if_5_40_true:
  %r155 = load i32, i32* @ptr
  %r156 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r155
  %r157 = call i32 @getch()
  store i32 %r157, i32* %r156
  br label %bb_if_5_40_end

bb_if_5_40_false:
  br label %bb_if_5_40_end

bb_if_5_40_end:
  %r159 = icmp eq i32 %r200, 93
  br i1 %r159, label %bb30_43_next, label %bb_if_5_43_false

bb30_43_next:
  %r160 = load i32, i32* @ptr
  %r161 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r160
  %r162 = load i32, i32* %r161
  %r163 = icmp ne i32 %r162, 0
  br i1 %r163, label %bb_if_5_43_true, label %bb_if_5_43_false

bb_if_5_43_true:
  %r201 = add i32 1, 0
  br label %bb_while_7_45_cond

bb_while_7_45_cond:
  %r202 = phi i32 [ %r197, %bb_if_5_43_true ], [ %r205, %bb_if_9_51_end ]
  %r203 = phi i32 [ %r200, %bb_if_5_43_true ], [ %r206, %bb_if_9_51_end ]
  %r204 = phi i32 [ %r201, %bb_if_5_43_true ], [ %r210, %bb_if_9_51_end ]
  %r165 = icmp sgt i32 %r204, 0
  br i1 %r165, label %bb_while_7_45_whilestms, label %bb_while_7_45_bre

bb_while_7_45_whilestms:
  %r167 = sub i32 %r202, 1
  %r205 = add i32 %r167, 0
  %r169 = getelementptr i32, i32* %r113, i32 %r205
  %r170 = load i32, i32* %r169
  %r206 = add i32 %r170, 0
  %r172 = icmp eq i32 %r206, 91
  br i1 %r172, label %bb_if_9_48_true, label %bb_if_9_48_false

bb_if_9_48_true:
  %r174 = sub i32 %r204, 1
  %r207 = add i32 %r174, 0
  br label %bb_if_9_48_end

bb_if_9_48_false:
  br label %bb_if_9_48_end

bb_if_9_48_end:
  %r208 = phi i32 [ %r207, %bb_if_9_48_true ], [ %r204, %bb_if_9_48_false ]
  %r176 = icmp eq i32 %r206, 93
  br i1 %r176, label %bb_if_9_51_true, label %bb_if_9_51_false

bb_if_9_51_true:
  %r178 = add i32 %r208, 1
  %r209 = add i32 %r178, 0
  br label %bb_if_9_51_end

bb_if_9_51_false:
  br label %bb_if_9_51_end

bb_if_9_51_end:
  %r210 = phi i32 [ %r209, %bb_if_9_51_true ], [ %r208, %bb_if_9_51_false ]
  br label %bb_while_7_45_cond

bb_while_7_45_bre:
  br label %bb_if_5_43_end

bb_if_5_43_false:
  br label %bb_if_5_43_end

bb_if_5_43_end:
  %r211 = phi i32 [ %r202, %bb_while_7_45_bre ], [ %r197, %bb_if_5_43_false ]
  %r212 = phi i32 [ %r203, %bb_while_7_45_bre ], [ %r200, %bb_if_5_43_false ]
  %r213 = phi i32 [ %r204, %bb_while_7_45_bre ], [ %r199, %bb_if_5_43_false ]
  %r180 = add i32 %r211, 1
  %r214 = add i32 %r180, 0
  br label %bb_while_3_23_cond

bb_while_3_23_bre:
  ret void
}

define i32 @main( ) {
bb3:
  call void @_sysy_starttime(i32 76)
  call void @read_program()
  %r181 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 0
  call void @interpret(i32* %r181)
  call void @putch(i32 10)
  call void @_sysy_stoptime(i32 80)
  ret i32 0
}

