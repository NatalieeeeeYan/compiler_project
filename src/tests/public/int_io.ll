declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@ascii_0 = global i32 48
define i32 @my_getint( ) {
bb1:
  %r169 = add i32 0, 0
  %r170 = add i32 0, 0
  %r171 = add i32 0, 0
  br label %bb_while_5_7_cond

bb_while_5_7_cond:
  %r172 = phi i32 [ %r171, %bb1 ], [ %r173, %bb_if_9_9_true ]
  %r102 = icmp sgt i32 1, 0
  br i1 %r102, label %bb_while_5_7_whilestms, label %bb_while_5_7_bre

bb_while_5_7_whilestms:
  %r103 = call i32 @getch()
  %r104 = load i32, i32* @ascii_0
  %r105 = sub i32 %r103, %r104
  %r173 = add i32 %r105, 0
  %r107 = icmp slt i32 %r173, 0
  br i1 %r107, label %bb_if_9_9_true, label %bb25_9_next

bb25_9_next:
  %r109 = icmp sgt i32 %r173, 9
  br i1 %r109, label %bb_if_9_9_true, label %bb_if_9_9_false

bb_if_9_9_true:
  br label %bb_while_5_7_cond

bb_if_9_9_false:
  br label %bb_while_5_7_bre

bb_while_5_7_bre:
  %r174 = phi i32 [ %r172, %bb_while_5_7_cond ], [ %r173, %bb_if_9_9_false ]
  %r175 = add i32 %r174, 0
  br label %bb_while_5_17_cond

bb_while_5_17_cond:
  %r176 = phi i32 [ %r175, %bb_while_5_7_bre ], [ %r179, %bb_if_9_19_end ]
  %r177 = phi i32 [ %r174, %bb_while_5_7_bre ], [ %r178, %bb_if_9_19_end ]
  %r111 = icmp sgt i32 1, 0
  br i1 %r111, label %bb_while_5_17_whilestms, label %bb_while_5_17_bre

bb_while_5_17_whilestms:
  %r112 = call i32 @getch()
  %r113 = load i32, i32* @ascii_0
  %r114 = sub i32 %r112, %r113
  %r178 = add i32 %r114, 0
  %r116 = icmp sge i32 %r178, 0
  br i1 %r116, label %bb26_19_next, label %bb_if_9_19_false

bb26_19_next:
  %r118 = icmp sle i32 %r178, 9
  br i1 %r118, label %bb_if_9_19_true, label %bb_if_9_19_false

bb_if_9_19_true:
  %r120 = mul i32 %r176, 10
  %r122 = add i32 %r120, %r178
  %r179 = add i32 %r122, 0
  br label %bb_if_9_19_end

bb_if_9_19_false:
  br label %bb_while_5_17_bre

bb_if_9_19_end:
  br label %bb_while_5_17_cond

bb_while_5_17_bre:
  %r180 = phi i32 [ %r177, %bb_while_5_17_cond ], [ %r178, %bb_if_9_19_false ]
  ret i32 %r176
}

define i32 @mod( i32 %r124, i32 %r126 ) {
bb2:
  %r183 = add i32 0, 0
  %r184 = add i32 %r124, 0
  %r185 = add i32 0, 0
  %r186 = add i32 %r126, 0
  %r131 = sdiv i32 %r184, %r186
  %r133 = mul i32 %r131, %r186
  %r134 = sub i32 %r184, %r133
  ret i32 %r134
}

define void @my_putint( i32 %r135 ) {
bb3:
  %r189 = add i32 0, 0
  %r190 = add i32 %r135, 0
  %r137 = alloca [ 16 x i32 ]
  %r191 = add i32 0, 0
  %r192 = add i32 0, 0
  br label %bb_while_5_38_cond

bb_while_5_38_cond:
  %r193 = phi i32 [ %r190, %bb3 ], [ %r195, %bb_while_5_38_whilestms ]
  %r194 = phi i32 [ %r192, %bb3 ], [ %r196, %bb_while_5_38_whilestms ]
  %r140 = icmp sgt i32 %r193, 0
  br i1 %r140, label %bb_while_5_38_whilestms, label %bb_while_5_38_bre

bb_while_5_38_whilestms:
  %r142 = getelementptr [16 x i32 ], [16 x i32 ]* %r137, i32 0, i32 %r194
  %r144 = call i32 @mod(i32 %r193, i32 10)
  %r145 = load i32, i32* @ascii_0
  %r146 = add i32 %r144, %r145
  store i32 %r146, i32* %r142
  %r148 = sdiv i32 %r193, 10
  %r195 = add i32 %r148, 0
  %r150 = add i32 %r194, 1
  %r196 = add i32 %r150, 0
  br label %bb_while_5_38_cond

bb_while_5_38_bre:
  br label %bb_while_5_43_cond

bb_while_5_43_cond:
  %r197 = phi i32 [ %r194, %bb_while_5_38_bre ], [ %r198, %bb_while_5_43_whilestms ]
  %r152 = icmp sgt i32 %r197, 0
  br i1 %r152, label %bb_while_5_43_whilestms, label %bb_while_5_43_bre

bb_while_5_43_whilestms:
  %r154 = sub i32 %r197, 1
  %r198 = add i32 %r154, 0
  %r156 = getelementptr [16 x i32 ], [16 x i32 ]* %r137, i32 0, i32 %r198
  %r157 = load i32, i32* %r156
  call void @putch(i32 %r157)
  br label %bb_while_5_43_cond

bb_while_5_43_bre:
  ret void
}

define i32 @main( ) {
bb4:
  %r201 = add i32 0, 0
  call void @_sysy_starttime(i32 51)
  %r202 = add i32 0, 0
  %r159 = call i32 @my_getint()
  %r203 = add i32 %r159, 0
  br label %bb_while_5_53_cond

bb_while_5_53_cond:
  %r204 = phi i32 [ %r201, %bb4 ], [ %r206, %bb_while_5_53_whilestms ]
  %r205 = phi i32 [ %r203, %bb4 ], [ %r207, %bb_while_5_53_whilestms ]
  %r161 = icmp sgt i32 %r205, 0
  br i1 %r161, label %bb_while_5_53_whilestms, label %bb_while_5_53_bre

bb_while_5_53_whilestms:
  %r163 = call i32 @my_getint()
  %r206 = add i32 %r163, 0
  call void @my_putint(i32 %r206)
  call void @putch(i32 10)
  %r166 = sub i32 %r205, 1
  %r207 = add i32 %r166, 0
  br label %bb_while_5_53_cond

bb_while_5_53_bre:
  call void @_sysy_stoptime(i32 58)
  ret i32 0
}

